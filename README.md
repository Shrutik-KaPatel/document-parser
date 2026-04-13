# Document Parser

A C program that parses a raw text document into a structured hierarchy of paragraphs, sentences and words using multi-level pointers.

## Overview

The program converts a flat string into a `char****` structure representing:

- `char*` — a word
- `char**` — a sentence (collection of words separated by spaces)
- `char***` — a paragraph (collection of sentences separated by periods)
- `char****` — a document (collection of paragraphs separated by newlines)

## Functions

- `get_document(char* text)` — parses the raw input string into the full document structure
- `kth_paragraph(char**** document, int k)` — returns the kth paragraph
- `kth_sentence_in_mth_paragraph(char**** document, int k, int m)` — returns the kth sentence in the mth paragraph
- `kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n)` — returns the kth word in the mth sentence of the nth paragraph

## Compilation

```bash
gcc document_parser.c -o document_parser
```

## Usage

```bash
./document_parser
```

Input format:
```
2
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3
1 2
2
5
6
2 1 1
4
3 1 1 1
```

Expected output:
```
Learning pointers is more fun.It is good to have pointers.
Learning C is fun
Learning
```

## Concepts Used

- Dynamic memory allocation with `malloc` and `calloc`
- Multi-level pointer dereferencing
- String parsing with `strncpy`
- Delimiter-based tokenisation (space, period, newline)

## Project Structure

```
document-parser/
├── document_parser.c
├── plan.txt
└── .gitignore
```
