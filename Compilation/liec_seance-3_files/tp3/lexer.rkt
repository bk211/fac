#lang racket/base

(require parser-tools/lex
         (prefix-in : parser-tools/lex-sre))

(require racket/port
        racket/trace
        parser-tools/yacc)


(define-empty-tokens operators
    (LFini
    LOpar LCpar LPlus LMoins
    LFois LDivise LEq))

(define-tokens numbers (LNumb))

(define tokenize
    (lexer
        (whitespace     (tokenize input-port))
        ((eof)          (token-LFini))
        ((:+ numeric)   (token-LNumb (string->number lexeme)))
        ("("            (token-LOpar))
        (")"            (token-LCpar))
        ("+"            (token-LPlus))
        ("-"            (token-LMoins))
        ("*"            (token-LFois))
        ("/"            (token-LDivise))
        ("="            (token-LEq))
        (any-char       (error (format "Unrecognized char '~a' at offset ~a."
                                        lexeme (position-offset start-pos))))
    )

)

(struct Plus (a b) #:transparent)
(struct Moins  (a b) #:transparent)
(struct Divise  (a b) #:transparent)
(struct Fois  (a b) #:transparent)
(struct Par  (a) #:transparent)
(struct Number (a) #:transparent)


(define parse1
    (parser
        (tokens operators numbers)
        (grammar
            (expr
                ((numb)                     $1)
                ((expr LPlus expr)          (Plus $1 $3))
                ((expr LMoins expr)         (Moins $1 $3))
                ((expr LDivise expr)        (Divise $1 $3))
                ((expr LFois expr)          (Fois $1 $3))
                )
                ;((LOpar expr LCpar)         (Par $1)))
            (numb
                ((LNumb)                   (Number $1))))
        (start expr)
        (end LFini)
        (error (lambda (ok? name value)
            (error (if value value 'Error)
            (if ok? "error" "invalid token"))))
    )
)

(define argv (current-command-line-arguments))
(cond
  ((= (vector-length argv) 1)
   (define in (open-input-string (vector-ref argv 0)))
   (write (parse1 (lambda () (tokenize in))))
   (newline))
  (else
   (eprintf "Usage: racket yacc.rkt \"string\"\n")
   (exit 1)))
