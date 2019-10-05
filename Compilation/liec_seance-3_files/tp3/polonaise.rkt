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
(struct Number (a) #:transparent)


(define parse1
    (parser
        (tokens operators numbers)
        (grammar
            (expr
                ((expr expr LPlus)          (Plus $1 $2))
                ((expr expr LMoins)         (Moins $1 $2))
                ((expr expr LDivise)        (Divise $1 $2))
                ((expr expr LFois)          (Fois $1 $2))
                ((numb)                     $1)
                )
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
(define in "")
(cond
  ((= (vector-length argv) 1)
   (set! in (open-input-string (vector-ref argv 0)))
   (println ">>loading..."))
  (else
   (eprintf "Usage: racket yacc.rkt \"string\"\n")
   (exit 1)))

(define resultat (parse1 (lambda () (tokenize in))))
;;(write resultat)
;;(newline)
(define (executer in)
    (cond
        ((Number? in) (Number-a in))
        ((Plus? in) (+ (executer (Plus-a in)) (executer (Plus-b in))))
        ((Moins? in) (- (executer (Moins-a in)) (executer (Moins-b in))))
        ((Fois? in) (* (executer (Fois-a in)) (executer (Fois-b in))))
        ((Divise? in) (/ (executer (Divise-a in)) (executer (Divise-b in))))
    )
)
(executer resultat)
