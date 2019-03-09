#lang racket
(require graphics/turtles)

(turtles #t)
(define (f n)
(begin
  (draw n)
  (turn 45)
  (draw n)
  (turn 135)
  (draw n)
  (turn 45)
  (draw n)))

(define (g d n)
  (begin
    (f d)
    (turn 150)
    (if (= n 0) (move 0)
        (g d (- n 1))
     )))
;(g 60 5)

(define (h d r n)
  (begin
    (draw d)
    (turn (- (random r) (/ r 2)))
    (if (= n 0) (move 0)
        (h d r (- n 1)))))
;(h 10 90 20)

(define (i d r n q)
  (begin
    (home)
    (turn (random 360))
    (h d r n)
    (if (= q 0) (move 0)
        (i d r n (- q 1)))))

;(i 10 90 20 20)

(define (j r n)
(begin
  (draw 2)
  (turn r)
  (if (= n 0) (move 0)
      (j r (- n 1)))))
(j 2 90)
;(j -2 360)

