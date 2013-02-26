;5.1
;a

((lambda (x) (cons x x)) (car '(1 2 3)))

;b
;((lambda (w z) (cons w (+ w z))) (car x) z)
;((lambda (w)
;    ((lambda (y) (cons w y)) (+ w z))) (car x))
((lambda (w)
      ((lambda (y) (cons w y)) (+ w 4))) (car '(1 2 3)))
;((lambda (w)
;    ((lambda(z) (cons w (+ w z))) z)) (car x))
((lambda (w)
    ((lambda(z) (cons w (+ w z))) 4)) (car '(1 2 3)))
