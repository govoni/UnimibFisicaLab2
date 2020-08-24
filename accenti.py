#!/Usr/bin/env python 

import argparse 
import re

if __name__ == "__main__":

  parser = argparse.ArgumentParser ()
  parser.add_argument ('--filemd', '-r', action='store', help='README.md to be indexed')
  args = parser.parse_args ()
  readme = args.filemd

  newlines = []
  with open (readme, 'r') as f :
    for line in f.readlines () :
      if line.startswith ("#") : newlines.append (line)
      else :
        line = line.replace ("a'", "&agrave;")
        line = line.replace ("che'", "ch&eacute;")
        line = line.replace ("e'", "&egrave;")
        line = line.replace ("i'", "&igrave;")
        line = line.replace ("o'", "&ograve;")
        line = line.replace ("u'", "&ugrave;")
        newlines.append (line)

  f = open (readme + "acc.md", "w")
  for line in newlines :
    f.write (line)
  f.close ()