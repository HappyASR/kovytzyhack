#!/usr/bin/python3
# -*- coding:utf-8 -*-
# (c) 2016  XingXing(HappyASR#gmail.com)

import os
import re
import sys


def parse_map(filemap):
    map_list = []
    map_dat = open(filemap).read()
    #.rom            0x0000000000100000   0x38a130
    r = re.findall(r"\n.rom\s+0x(\w+)", map_dat)
    rom_base = int(r[0], 16)
    #                0x0000000000100000                __patch_end_0x55c18
    r = re.findall(r"\n\s+0x(\w+)\s+(__patch_\S+_\S+)", map_dat)
    for c in r:
        map_list.append((int(c[0], 16) - rom_base, c[1]))
    map_list.sort()
    return map_list

def patch_dat(dat_ori, dat_pat, pat_start, pat_end):
    dat = dat_ori[:pat_start]
    dat += dat_pat[pat_start:pat_end]
    dat += dat_ori[pat_end:]
    return dat


def patch_file(crosstools, fileelf, filemap, fileori, fileout):
    print('processing', fileout)
    map_list = parse_map(filemap)

    dat_ori = open(fileori, 'rb').read()
    len_ori = len(dat_ori)
    #dat_pat = open(filerom,'rb').read()+open(fileram,'rb').read()
    os.system("%sobjcopy -Obinary -j.rom %s rom.bin" % (crosstools, fileelf))
    os.system("%sobjcopy -Obinary -j.ram %s ram.bin" % (crosstools, fileelf))
    dat_pat = open("rom.bin", 'rb').read() + open("ram.bin", 'rb').read()
    os.remove("rom.bin")
    os.remove("ram.bin")
    for i in range(len(map_list) // 2):
        pat_start = map_list[2 * i][0]
        pat_end = map_list[2 * i + 1][0]
        if (pat_end != pat_start):
            dat_ori = patch_dat(dat_ori, dat_pat, pat_start, pat_end)

    c_addr = map_list[-1][0]
    dat_ori = dat_ori[:c_addr] + dat_pat[c_addr:] + dat_ori[len(dat_pat):]
    len_now = len(dat_ori)
    dat_ori += b'\xFF' * (len_ori - len_now)
    open(fileout, 'wb').write(dat_ori)
    print("Saved OK.")


if __name__ == '__main__':
    if len(sys.argv) > 5:
        patch_file(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4],
                   sys.argv[5])
    else:
        print("%s <CROSS-PREFIX> <ELF> <MAP> <ORI_BIN> <OUTPUT>" % sys.argv[0])
        sys.exit(1)
