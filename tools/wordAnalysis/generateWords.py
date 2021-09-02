from loadDict import loadResultAsList as lr

def PrintGameWords():

    combList = lr("expandedCombDict.txt")

    chosenCombWordList = combList[5][0]
    with open('GameWords.h', 'w') as f:

        print('#ifndef GameWords_h', file=f)
        print('#define GameWords_h', file=f)
        print('', file=f)
        print('namespace Game', file=f)
        print('{', file=f)
        print('', file=f)
        print('    String possibleWords[' + str(len(chosenCombWordList)) + '] = ', file=f)
        print('    {', file=f)

        for word in chosenCombWordList:    
            print('        String("' + word + '"),', file=f)

        print('    };', file=f)
        print('}', file=f)
        print('#endif', file=f)

    return

PrintGameWords()