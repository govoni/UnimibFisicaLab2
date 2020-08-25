#!/Usr/bin/env python 

import argparse 
import re

if __name__ == "__main__":

  parser = argparse.ArgumentParser ()
  parser.add_argument ('--readme', '-r', action='store', default='README.md', help='README.md to be indexed')
  args = parser.parse_args ()
  readme = args.readme

  title_lines = []
  with open (readme, 'r') as f :
      for line in f.readlines () :
        if line.startswith ("##") :
          title_lines.append (line.strip ())

  # ssotituisco trattini agli spazi
  title_links = [line.replace (' ', '-') for line in title_lines]
  # rimuovo le non lettere
  title_links = [line.replace ('`', '') for line in title_links]
  title_links = [line.replace ('+', '') for line in title_links]
  title_links = [line.replace ('.', '') for line in title_links]
  title_links = [line.replace (':', '') for line in title_links]
  title_links = [line.replace ('*', '') for line in title_links]
  title_links = [line.replace (',', '') for line in title_links]
  title_links = [line.replace ('(', '') for line in title_links]
  title_links = [line.replace (')', '') for line in title_links]
  title_links = [line.replace ('!', '') for line in title_links]
  title_links = [line.replace ('?', '') for line in title_links]
  title_links = [line.replace ('\'', '') for line in title_links]
  title_links = [line.replace ('/', '') for line in title_links]
  title_links = [line.replace ('<', '') for line in title_links]
  title_links = [line.replace ('>', '') for line in title_links]
  title_links = [line.replace ('&', '') for line in title_links]
  title_links = [line.replace (';', '') for line in title_links]
  title_links = [line.replace ('=', '') for line in title_links]
  # tutto minuscolo
  title_links = [line.lower () for line in title_links]


  final_text = [] 
  for i in range (len (title_lines)) :
    text_line = ""
    if title_lines[i].startswith ("###") : 
      text_line += "    * "
      title_links[i] = title_links[i].replace ("###-", "#")
      title_lines[i] = title_lines[i].replace ("### ", "")
    else : 
      text_line += "  * "
      title_links[i] = title_links[i].replace ("##-", "#")
      title_lines[i] = title_lines[i].replace ("## ", "")
    title_links[i] = title_links[i].replace ("#", "")
    text_line += "[" + title_lines[i] + "]"
    text_line += "(#" + title_links[i] + ")"
    final_text.append (text_line)

  print "## Indice\n"

  for text_line in final_text: print text_line

  print "\n![linea](../immagini/linea.png)\n"
