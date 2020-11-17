# ifTest

## What would be better?
```
if (!(A == B && C == D))
    body;
```
```
if (A != B || C != D)
    body;
```
```
if (A == B && C == D);
else
    body;
```
The assembly codes generated from this 3 ways are exactly same!
So i recommend the best readable way and the best matching way to your intention.

