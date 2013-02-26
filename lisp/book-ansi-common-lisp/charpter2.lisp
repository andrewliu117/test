;;;; "ansi common lisp" charper2 quiz
;2.2
(cons 'a '(b c))
(cons 'a (cons 'b '(c)))
(cons 'a (cons 'b (cons 'c nil)))
(cons 'a (cons 'b (cons 'c ()))

;2.3
(defun myfour (lst)
      (car (cdr (cdr (cdr lst)))))

;2.4

(defun mymax (x y)
    (if (> x y)
        x
        y))

;2.6 c
;apply (not funcall)

;2.7

(defun havelist (lst)
    (if (null lst)
        nil
        (if (listp (car lst))
            t
            (havelist (cdr lst)))))


(defun havelist (lst)
    (setf ret nil)
    (dolist (obj lst)
        (if (listp obj)
            (setf ret t)))
    ret )

;2.8 a
(defun pdot (n) (if (> n 0) (let ((a (- n 1))) (format t ".") (pdot a))))

(defun pdot1 (n) (do ((i 0 (+ i 1))) ( (> i n) 'done) (format t ".")))

;2.8 b

(defun atimes (lst) 
    (if (null lst) 
        0
        (if (eql 'a (car lst)) 
            (+ (atimes (cdr lst)) 1)
            (atimes (cdr lst)))))

(defun atimes1 (lst)
    (setf times 0)
    (dolist (obj lst)
        (if (eql 'a obj)
            (setf times (+ times 1))))
    times)

;2.9

(defun summit (lst)
    (setf lst (remove nil lst))
    (apply #'+ lst))

(defun summit (lst)
    (if (null lst)
        0
        (let ((x (car lst)))
            (if (null x)
                (summit (cdr lst))
                (+ x (summit (cdr lst)))))))
