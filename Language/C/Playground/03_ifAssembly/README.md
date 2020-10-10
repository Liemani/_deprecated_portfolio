# if assembly code

```
// 05_ifAssembly.c
if (!isInWord) {
    if (!isSpace(inputCharacter)) {
        isInWord = IN_WORD;
    }
} else {
    if (isSpace(inputCharacter)) {
        ++wordCount;
        isInWord = OUT_WORD;
    }
}
```
```
// 06_ifAssembly2.c
if (!isInWord && !isSpace(inputCharacter)) {
    isInWord = IN_WORD;
} else if (isInWord && isSpace(inputCharacter)) {
    ++wordCount;
    isInWord = OUT_WORD;
}
```
```
// 07_ifAssembly3.c
if (!isInWord) {
    if (!isSpace(inputCharacter)) {
        isInWord = IN_WORD;
    }
} else if (isSpace(inputCharacter)) {
    ++wordCount;
    isInWord = OUT_WORD;
}
```

`05_ifAssembly.s` and `07_ifAssembly3.s` are exactly same. And `06_ifAssembly2.s` is longer than others. `06` and `07` are not common. So i would choose `05`.
