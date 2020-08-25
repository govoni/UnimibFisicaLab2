#!/Usr/bin/env python 
# coding=utf-8

import argparse 
import re
import os

if __name__ == "__main__":

  parser = argparse.ArgumentParser ()
  parser.add_argument ('--filemd', '-r', action='store', help='README.md to be indexed')
  args = parser.parse_args ()
  readme = args.filemd

  newlines = []
  with open (readme, 'r') as f :
    for line in f.readlines () :
      line = line.replace ("a'", "à")
      line = line.replace ("che'", "ché")
      line = line.replace ("e'", "è")
      line = line.replace ("i'", "ì")
      line = line.replace ("o'", "ò")
      line = line.replace ("u'", "ù")
      newlines.append (line)

  f = open (readme + '.accenti', 'w')
  os.rename (readme, readme + '.old')
  os.rename (readme + '.accenti', readme)
  for line in newlines :
    f.write (line)
  f.close ()
