#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre)
         "helper.rkt")

(provide constants operators get-token)

(define-tokens constants
  (Lnum Lstr Lident))

(define-empty-tokens operators
  (Leof
   Lplus
   Lassign
   Lopar Lcpar Lcomma Lsep))


(define-lex-abbrev identifier
    (:: alphabetic (:* (:or "_" alphabetic numeric))))


(define get-token
  (lexer-src-pos
   [(eof)        (token-Leof)]
   ;[#\newline         (token-Lsep)]
   ["\n"         (token-Lsep)]
   [whitespace   (return-without-pos (get-token input-port))]

   ["="          (token-Lassign)]
   ["+"          (token-Lplus)]
   ["("          (token-Lopar)]
   [")"          (token-Lcpar)]
   [","          (token-Lcomma)]

   [identifier       (token-Lident (string->symbol lexeme))]
   [(:+ numeric) (token-Lnum (string->number lexeme))]
   ["\""         (token-Lstr (read-str input-port))]
   [any-char (err (format "unrecognized character '~a'" lexeme)
                  start-pos)]))

(define read-str
  (lexer
   ["\\\""   (string-append "\"" (read-str input-port))]
   ["\""     ""]
   [any-char (string-append lexeme (read-str input-port))]))
