import pandas as pd
import numpy as np

def loadWords(filename):
    with open(filename) as word_file:
        valid_words = word_file.read().split()
    return valid_words

allComb   = list( )
combList  = ['','','','','','']
alphabet  = ['a','b','c','d','e', 'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

# Generate a list of all combinations of the letters
def populateCombinations(combListLength, combPos = 0, alphPos = 0):
    global allComb, combList
    loopCount = 0
    if(combPos <= combListLength):
        for index in range(alphPos,len(alphabet)):
            combList[combPos] = alphabet[index]
            if(combPos != (combListLength - 1)):
                populateCombinations(combListLength, combPos + 1, alphPos + 1 + loopCount)
            else:
                allComb.append("".join(combList))
            loopCount += 1
        return
    else:
        return

def scanWords(allComDict):
    counter = 0
    total = len(allCombDict)
    for key, value in allCombDict.items():
        print("{0} combination of {1}: {2} percent".format(counter, total, counter/total*100))
        for gWord in googleWordsList:
            mismatch = False
            for c in gWord:
                if(c not in key):
                    mismatch = True
                    continue
            if(not mismatch):
                allCombDict[key] = allCombDict.get(key,value) + 1
                continue
        counter += 1
    return


def mainLoop():

    populateCombinations(6)
    allCombDict = dict.fromkeys(allComb,0)
    googleWordsList = loadWords('google-10000-english.txt')
    scanWords(allCombDict)

    with open('out.txt', 'w') as f:
        print(allCombDict, file=f)

    return

