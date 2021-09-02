from wordFilter import loadWords as lw
import numpy as np

def loadResultAsList(path):
    with open(path,'r') as inf:
        dict_from_file = eval(inf.read())

    sorted_d = sorted(((value, key) for (key,value) in dict_from_file.items()), reverse=True)

    return sorted_d

def scanWordsWithComb(comb, wordsDict):
    counter = 0
    total = len(wordsDict)
    for key, value  in wordsDict.items():
        print( comb + " : " + "{0} word of {1}: {2:.2f}%".format(counter, total, counter/total*100), flush=True)
        match = True
        for c in key:
            if(c not in comb):
                match = False
                continue
        if(match):
            wordsDict[key] = wordsDict.get(key, value) + 1
            continue
        counter += 1
    return wordsDict


def WriteSummary():

    allScannedComb = loadResultAsList('resultDict.txt')
    subset = allScannedComb[0:15]
    expandedCombDict = dict()
    wordsDict = dict.fromkeys(lw('google-10000-english.txt'),0)

    # Maintining tuple structure from the tuple list
    for count, comb in subset:
        wordsDict = scanWordsWithComb(comb, wordsDict)
        # Filter the dictionary
        filtResultsDict = {k: v for k, v in wordsDict.items() if v == 1}
        filtResultsList = list(filtResultsDict.keys())

        # Remove all two letter combinations
        filtResultsList = [item for item in filtResultsList if not (len(item) <= 2)]


        expandedCombDict.update({comb:filtResultsList})
        wordsDict = dict.fromkeys(wordsDict,0)

    with open('expandedCombDict.txt', 'w') as f:
        print(expandedCombDict, file=f)

    return



def DisplayResults():

    expandedChosenComb = loadResultAsList("expandedCombDict.txt")

    for key, value in expandedChosenComb:
        print(value)
        print(key)
        print(len(key))
        print("------------------")

    return


# For breakpoint


# WriteSummary()

DisplayResults()

x = 0

# aeprst': ['are', 'see', 'state', 'set', 'part', 'states', 'area', 'per', 'art', 'rate', 'press', 'estate', 'start', 'test', 'street', 'rates', 'east', 'paper', 'star', 'areas', 'rss', 'sep', 'arts', 'past', 'parts', 'apr', 'step', 'pre', 'sat', 'ass', 'sea', 'tree', 'peter', 'stars', 'est', 'pass', 'rest', 'rape', 'sets', 'papers', 'pst', 'pet', 'appear', 'tests', 'steps', 'separate', 'stats', 'appears', 'spa', 'tape', 'assets', 'rare', 'eat', 'seat', 'tea', 'trees', 'pets', 'stress', 'starts', 'rear', 'psp', 'prepare', 'res', 'treat', 'asset', 'para', 'peer', 'taste', 'seats', 'era', 'asp', 'par', 'apart', 'streets', 'epa', 'pat', 'ear', 'rep', 'repeat', 'ease', 'pee', 'assess', 'app', 'tee', 'passes', 'strap', 'rap', 'rat', 'spears', 'sees', 'aaa', 'reset', 'spare', 'starter', 'pepper', 'tapes', 'pete', 'sept', 'tears', 'paste', 'easter', 'tap', 'rats', 'stat', 'apps', 'prep', 'sara', 'sap', 'arrest', 'trap', 'pts', 'rrp', 'ste', 'ears', 'ser', 'str', 'tar', 'retreat', 'estates', 'pest', 'erp', 'apt', 'pas', 'sas', 'ate', 'pasta', 'peas', 'tear', 'ata', 'seas', 'peers', 'spas']



