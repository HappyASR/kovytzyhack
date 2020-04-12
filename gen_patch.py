#!/usr/bin/python3
# -*- coding:utf-8 -*-
# (c) 2016  XingXing(HappyASR#gmail.com)

import os
import re
import sys

TOKEN_PATCH = 'XXPATCH'


#return (org,file,line,str)
def process_asm(filename):
    resp = []
    print('processing', filename)
    dat = open(filename, encoding='UTF-8').read()
    dat = re.sub('//[ \t]*' + TOKEN_PATCH, '//$$PATCH', dat)
    dat = dat.split(TOKEN_PATCH)
    resp.append((0, filename, 0, dat[0]))
    linecount = dat[0].count('\n')
    for c in dat[1:]:
        c = c.strip(' ').strip('\t')
        org_str = c.split('(')[1].strip()
        org_str = re.compile(r'[), ]').split(org_str)[0]
        if org_str[:2] == '0x':
            org_val = int(org_str, 16) & 0xfffffff
        else:
            org_val = int(org_str) & 0xfffffff
        resp.append((org_val, filename, linecount, '\t' + TOKEN_PATCH + c))
        linecount += c.count('\n')
    return resp


def gen_patch(addr_code, outfile, inpdir):
    print("outfile=%s" % outfile)
    basepathlen = len(outfile) - len('src/patch.S')
    patch_all = []
    for f in inpdir:
        patch_all.extend(process_asm(f))

    patch_all.sort()
    f = open(outfile, 'w+', encoding='UTF-8')
    f.write('''
#include "xxpacth_include.h"
.section .patch,"ax"

XXEXPORT_START(dumpy)

''')
    for c in patch_all:
        #print c
        f.write('.file "%s"\n' % c[1][basepathlen:].replace('\\', '\\\\'))
        f.write('.line %d\n' % c[2])
        f.write(c[3] + '\n')

    f.write('''.file __FILE__
.line __LINE__
XXEXPORT_END(dumpy)
.org %s
XXEXPORT_START(ccode)
''' % addr_code)
    f.close()


if __name__ == '__main__':
    if (len(sys.argv) > 3):
        gen_patch(sys.argv[1], sys.argv[2], sys.argv[3:])
    else:
        print("%s <addr> <out> <input...>" % sys.argv[0])
        sys.exit(1)
