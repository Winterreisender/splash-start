# splash-start

Add splash for apps

## Usage
Add splash screen for windows in CLI:
```bash
splash-start -t 2000 -p "<Path to File>.jpg" -w 841 -h 514 & code

# Or
alias code='splash-start -t 2000 -p "<Path to File>.jpg" -w 841 -h 514 & code'
code
```

Change splash for PyCharm:
1. Disable splash built in Pycharm
2. Modify shotcut, add `splash-start -t 2000 -p "<Path to File>.jpg" -w 841 -h 514` before
