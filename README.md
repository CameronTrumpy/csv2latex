# csv2latex
csv2latex is a small tool written for use in EECS 203. Writing truth tables in raw latex (even in a latex editor like overleaf) is not a very comfortable process, so this tool allows you to write out your truth table in a spreadsheet application. Exporting your spreadsheet to csv, and then running through the tool will output a txt file with the table formatted in latex.

## CSV Syntax
The supported syntax for logical operations in the CSV entries is as follows.

| Logical Operation | CSV Formatting | Latex Output |
|-------------------|----------------|--------------|
| $\lnot$           | NOT            | \neg         |
| $\land$           | AND            | \land        |
| $\lor$            | OR             | \lor         |
| $\rightarrow$     | IF             | \rightarrow  |
| $\iff$            | IFF            | \equiv       |

## Example CSV Input
```
p,q,!p,!q,(p AND q),(p AND q) OR !p OR !q
T,T,F,F,T,T
T,F,F,T,F,T
F,T,T,F,F,T
F,F,T,T,F,T
```

## Latex Output

$$ \begin{array}{| c | c | c | c | c | c |} 
\hline
p & q & \neg p & \neg q & (p \land q) & (p \land q) \lor \neg p \lor \neg q\\
\hline
T & T & F & F & T & T\\
T & F & F & T & F & T\\
F & T & T & F & F & T\\
F & F & T & T & F & T\\
\hline
\end{array}$$

```
\begin{displaymath} \begin{array}{| c | c | c | c | c | c |} 
\hline
p & q & \neg p & \neg q & (p \land q) & (p \land q) \lor \neg p \lor \neg q\\
\hline
T & T & F & F & T & T\\
T & F & F & T & F & T\\
F & T & T & F & F & T\\
F & F & T & T & F & T\\
\hline
\end{array} \end{displaymath}
```

## Execution
```console
$ make main.exe
$ ./main.exe
Welcome to csv2latex!
Enter CSV filename...
example.csv
```
Outputted .txt with latex will be saved in the current directory as [original-filename].txt
