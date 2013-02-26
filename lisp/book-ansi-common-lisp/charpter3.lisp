;;;; "ansi common lisp" charper3 quiz

;3.2

(defun new-union (x y)
    (dolist (obj y)
        (if (null (intersection x (list obj)))
            (setf x (append x (list obj)))))
    x)

;3.3

(defun occurrences (lst)
    (let ((acc nil))
        (dolist (obj lst)
            (let ((p (assoc obj acc)))
               (if p
                    (incf (cdr p))
                    (push (cons obj 1) acc))))
        (sort acc #'> :key #' cdr)))

;3.4
;'(a) and (a) in '((a) (b)) are different objects.
; (member '(a) '((a) (b)) :test #' equal) return not nil

;3.5
;a
(defun pos1+ (lst &optional (pos 0))
    (if (null lst)
        nil
        (let ((head (car lst)))
             (setf head (+ head pos))
             (setf pos (+ pos 1))
             (cons head (pos1+ (cdr lst) pos)))))
    
(defun pos1+ (lst &optional (pos 0))
    (if lst
        (cons (+ (car lst) pos) (pos1+ (cdr lst) (+ pos 1)))))

;b
(defun pos2+ (lst)
    (do ((lsta lst (cdr lsta))
         (i 0 (+ i 1))
         (acc nil (cons (+ (car lsta) i) acc)))
        ((not lsta) (reverse acc))))

(defun pos2+ (lst)
    (setf pos 0)
    (setf acc nil)
    (dolist (obj lst)
           (push (+ obj pos) acc)
           (incf pos)) 
    (reverse acc))

;c

(defun pos3+ (lst)
    (setf pos 0)
    (mapcar #' (lambda (x) (setf pos (+ pos 1)) (- (+ x pos) 1)) lst))

(defun pos3+ (lst)
    (setf pos -1)
    (mapcar #' (lambda (x) (+ x (incf pos))) lst))

;;3.6
; use car and cdr to implement these functions (not the original quiz, switch car and cdr)
; a

(defun cons (x y)
    (let ((lst '(nil . nil)))
        (setf (car lst) x
              (cdr lst) y)
        lst))

;b

; wrong, when "(mylist (cdr restarg))" called, a list will passed to mylist, and the first item of this list is list (cdr restarg), 
; so two funcs will be used in the right version
;(defun mylist (&rest restarg)
;    (if (not (null (car restarg)))
;        (cons (car restarg) (mylist (cdr restarg)))))

(defun mylist (&rest restarg)
    (mylist-0 restarg))
(defun mylist-0 (lst)
    (if lst
        (cons (car lst) (mylist-0 (cdr lst)))))
(defun mylist-0 (lst)
    (if lst
        (cons (car lst) (cdr lst))))

; using keyword &rest, the parameter returned is a list, and will return nil tested by null.
(defun bb (&rest args) (null args) )

;c

(defun mylength (lst)
    (if lst
        (+ 1 (mylength (cdr lst)))
        0))


;d
(defun mymember (obj lst)
    (if lst
        (if (equal obj (car lst))
            lst
            (mymember obj (cdr lst)))
        nil))

(defun mymember (obj lst)
    (if (null lst) 
        (return-from mymember nil))
    (if (equal obj (car lst))
        lst
        (mymember obj (cdr lst))))


;3.8

(defun showdots (lst)
    (if lst
        (progn
            (format t "(~a . " (car lst))
            (showdots (cdr lst))
            (format t ")"))
        (format t "~a" nil)))

(defun showdots (lst)
    (if lst
        (progn
            (if (atom (car lst))
                (format t "(~a . " (car lst))
                (progn
                    (format t "(")
                    (showdots (car lst))
                    (format t " . ")))
            (showdots (cdr lst))
            (format t ")"))
        (format t "~a" nil)))

;3.9

(defparameter *net* '((a b c) (b a c) (c a b d) (d c)))

(defun longest-path (start end net)
  (bfs end (list (list start)) net nil))

(defun bfs (end queue net reach)
  (if queue
      (let ((path (car queue)))
        (let ((node (car path)))
          (bfs end
               (append (cdr queue) (new-paths path node net))
               net
               (if (eql node end) path reach))))
      (reverse reach)))

(defun new-paths (path node net)
    (let (acc)
        (dolist (x (cdr (assoc node net)))
            (or (member x path)
                (push (cons x path) acc)))
    acc))
