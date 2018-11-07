# MathSyntaxAnalyzer

# Overview

- STEP1: 
    - ReversePolishNotation
    - 逆ポーランド記法による数式を演算するサンプルプログラム
- STEP2: 
    - Tokenizer
    - 数式をトークンに分割するサンプルプログラム
- STEP3:
    - MathSyntaxAnalyzer
    - STEP1, STEP2の両クラスを利用した、数式を演算するプログラム

# BNF

```
expr = term { ["+"|"-"] term };
term = factor { ["*"|"/"] factor };
factor = number | "(" expr ")";
number = ["-"] { digit } ["."{ digit }];
digit = "0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9";
```
