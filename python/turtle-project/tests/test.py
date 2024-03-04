#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

import unittest
from main import *
import yaml


class TestMain(unittest.TestCase):
    def testApplyRules(self):
        result = applyRules("a", "{a+a*[a-a]ca+a}", "b-cb-cb-cb")
        self.assertEqual(result, "{a+a*[a-a]ca+a}")

        result = applyRules("b", "{a+a*[a-a]ca+a}", "b-{bc++b}-b")
        self.assertEqual(result, "b-{bc++b}-b")

        result = applyRules("c", "{[a+a-a+a]*a}", "b+b-b")
        self.assertEqual(result, "c")

    def testProcessString(self):
        result = processString("a+b", "{a+a*[a-a]ca+a}", "b-cb-cb-cb")
        self.assertEqual(result, "{a+a*[a-a]ca+a}+b-cb-cb-cb")

        result = processString("a*b+ca", "{[a+a-a+a]*a}", "[b-cb+bb]*b+b")
        self.assertEqual(result, "{[a+a-a+a]*a}*[b-cb+bb]*b+b+c{[a+a-a+a]*a}")

        result = processString("ac[ab]*+bb", "aa+[+a[+a]-a+a]-[-a-[a]+a]", "bb+b-a+b-a-bb")
        self.assertEqual(result,
                         "aa+[+a[+a]-a+a]-[-a-[a]+a]c[aa+[+a[+a]-a+a]-[-a-[a]+a]bb+b-a+b-a-bb]*+bb+b-a+b-a-bbbb+b-a+b-a-bb")

    def testCreateLSystem(self):
        result = createLSystem(1, "a", "-a++b++a", "bb+b-a+b-a-bb")
        self.assertEqual(result, "-a++b++a")

        result = createLSystem(2, "a*b-ac", "+a-b*cab", "[b-cb+bb]*b+b")
        self.assertEqual(result,
                         "++a-b*cab-[b-cb+bb]*b+b*c+a-b*cab[b-cb+bb]*b+b*[[b-cb+bb]*b+b-c[b-cb+bb]*b+b+[b-cb+bb]*b+b[b-cb+bb]*b+b]*[b-cb+bb]*b+b+[b-cb+bb]*b+b-++a-b*cab-[b-cb+bb]*b+b*c+a-b*cab[b-cb+bb]*b+bc")

        result = createLSystem(3, "a-ca-ca-ca", "a*a+a-ca-a+a*a", "bb+b-a+b-a-bb")
        self.assertEqual(result,
                         "a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a-a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a*a*a+a-ca-a+a*a+a*a+a-ca-a+a*a-ca*a+a-ca-a+a*a-a*a+a-ca-a+a*a+a*a+a-ca-a+a*a*a*a+a-ca-a+a*a")

    def testGetFiles(self):
        if not os.path.isfile("entry.yaml"):
            f = open("entry.yaml", "x")
            f.close()
        if not os.path.isfile("out.txt"):
            f = open("out.txt", "x")
            f.close()
        if not os.path.isfile("kick.yaml"):
            f = open("kick.yaml", "x")
            f.close()
        if not os.path.isfile("sortie.txt"):
            f = open("sortie.txt", "x")
            f.close()
        result = getFiles([('-i', 'entry.yaml'), ('-o', 'out.txt')])
        self.assertEqual(result, ('entry.yaml', 'out.txt'))

        result = getFiles([('-i', 'kick.yaml'), ('-o', 'sortie.txt')])
        self.assertEqual(result, ('kick.yaml', 'sortie.txt'))

    def testReadFile(self):
        file1 = {'axiome': "a-ca-ca-ca", 'regles': {'a': "a+a*a+a+aa*aa+a+a*a+a", 'b': "bb+b-a+b-a-bb"}, 'angle': 90, 'taille': 5,
                 'niveau': 3}
        file2 = {'axiome': "-a++b++a", 'regles': {'a': "aa+[+a[+a]-a+a]-[-a-[a]+a]", 'b': "[b-cb+bb]*b+b"}, 'angle': 40, 'taille': 3,
                 'niveau': 2}
        file3 = {'axiome': "-a-a++a-a++a-a++a-a++a-a++a-a", 'regles': {'a': "a-a++a-a", 'b': "bb+b-a+b-a-bb"}, 'angle': 60, 'taille': 4,
                 'niveau': 1}

        with open("entree1.yaml", 'w') as stream:
            doc1 = yaml.dump(file1, stream)
        result = readFile("entree1.yaml")
        self.assertEqual(result, ("a-ca-ca-ca", "a+a*a+a+aa*aa+a+a*a+a", "bb+b-a+b-a-bb", 90, 5, 3))

        with open("entree2.yaml", 'w') as stream2:
            doc2 = yaml.dump(file2, stream2)
        result = readFile("entree2.yaml")
        self.assertEqual(result, ("-a++b++a", "aa+[+a[+a]-a+a]-[-a-[a]+a]", "[b-cb+bb]*b+b", 40, 3, 2))

        with open("entree3.yaml", 'w') as stream3:
            doc2 = yaml.dump(file3, stream3)
        result = readFile("entree3.yaml")
        self.assertEqual(result, ("-a-a++a-a++a-a++a-a++a-a++a-a", "a-a++a-a", "bb+b-a+b-a-bb", 60, 4, 1))


if __name__ == "__main__":
    unittest.main()
