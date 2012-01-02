import random

def generate_10():
  l = {}
  g = lambda c : c
  l[2] = g('(')
  l[3] = g(')')
  l[0] = g('+')
  l[1] = g('-')
  l[4] = g('/')
  l[5] = g('*')
  l[6] = g('%')
  l[7] = g(str(random.randint(1, 1000000)))

  res = ""
  for i in xrange (100000, 500000):
    res += str (random.randint (1000, 1000000))
    res += l[random.randint (0, 1)]
    res += str (random.randint (1000, 1000000))
  return "10\n0123456789\n" + str(len(res)) + "\n" + res


def generate_random():
  base = random.randint(2, 240)
  sym = [chr (i) for i in xrange (base - 1, -1, -1) if chr (i) not in [')', '(', '%', '/', '*', '-', '+']]
  i = 254
  while len (sym) < base:
    if chr (i) not in sym:
      sym.append (chr (i))
      i -= 1

  l = {}
  g = lambda c : c
  l[2] = g('(')
  l[3] = g(')')
  l[0] = g('+')
  l[1] = g('-')
  l[4] = g('/')
  l[5] = g('*')
  l[6] = g('%')
  l[7] = g(str(random.randint(1, 1000000)))

  res = ""
  for i in xrange (0, random.randint(1000, 100000)):
    res += str (sym[random.randint (1, base - 1)] * 15)
    res += l[random.randint(0, 1)]
    res += str (sym[random.randint (1, base - 1)] * 15)
  return str (base) + "\n" + "".join(sym) + "\n" + str (len (res)) + "\n" + res


def generate_42():
  base = 42
  sym = ['z', 'x', 'y', 'u', 'v', 'w', 't', 's', 'r', 'q', 'a', 'b', 'c', 'd', 'e',
      '0', 'f', '1', 'g', '2', 'h', '3', 'i', '4', 'j', '5', 'k', '6', 'l', '7', 'm',
      '8', 'n', '9', 'o', 'p', 'Q', 'P', 'S', 'A', 'B', 'T']
  res = ""
  l = {}
  g = lambda c : c
  l[2] = g('(')
  l[3] = g(')')
  l[0] = g('+')
  l[1] = g('-')
  l[4] = g('/')
  l[5] = g('*')
  l[6] = g('%')
  l[7] = g(str(random.randint(1, 1000000)))

  for i in xrange (0, random.randint(1000, 10000)):
    tmp = "d" + "".join(sym)
    res += tmp + tmp + tmp + tmp + tmp
    res += l[random.randint(0, 1)]
    res += tmp + tmp + tmp + tmp + tmp
  return "42\n" + "".join(sym) + "\n" + str(len(res)) + "\n" +res

import os

def main ():
  """
  This program aims to generates random arithmetic expressions
  of an arbitrary size and compare the bistro ref with the student's
  one.
  """
#  r = random.randint(0,1)
#  if r is 0:
  print generate_10 ()
#  else:
#    print generate_42 ()


if __name__ == "__main__":
  main()
