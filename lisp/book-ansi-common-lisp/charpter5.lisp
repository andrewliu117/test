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

;5.2
(defun mystery (x y)
    (cond ((null y) nil)
          ((eql (car y) x) 0)
          (t (let ((z (mystery x (cdry)))))
                  (and z (+ z 1)))))

;5.3

(defun square (x)
    (cond 
        ((and (integerp x) (> x 0) (< x 6) ) x)
        (t (* x x))))

;5.4
(defun month-num (m y)
   (+ (svref month (- m 1))
      ( case m
            ((1 2) 0)
             (3 4 5 6 7 8 9 10 11 12) (if (leap? y) 1 0))))

;5.5

(defun precedes (x vec)
    (setf l nil)
    (do ((i 1 (+ i 1)))
        ((= i (length vec)))
        (if (and (eql x (aref vec i)) (< 0 i))
            (push (aref vec (- i 1)) l)))
    (remove-duplicates l))

;5.6

;;repetition
(defun myintersperse  (x lst)
    (setf acc nil)
    (dolist (obj lst)
        (if acc
            (progn 
                (push x acc)
                (push obj acc))
            (push obj acc)))
    (reverse acc))

(defun intersperse (x lst)
    (do ((ls1 (reverse (cdr lst)) (cdr ls1))
         (ls2 nil (cons x (cons (car ls1) ls2))))
        ((not ls1) (cons (car lst) ls2))))

;;recursion
(defun myintersperse (x lst)
    (let ((retlst nil))
        (reverse (intersperse-0 x (push (car lst) retlst) (cdr lst))))) 

(defun myintersperse-0 (x retlst lst)
    (if lst
        (progn  
            (push x retlst)
            (push (car lst) retlst)
            (myintersperse-0 x retlst (cdr lst)))
        retlst))

(defun intersperse (x lst)
        (cons (car lst) (intersperse-0 x (reverse (cdr lst)) nil))) 

(defun intersperse-0 (x lst acc)
    (if lst
        (intersperse-0 x (cdr lst) (cons x (cons (car lst) acc)))
        acc))

;5.7

;a

;recursion
; only considered a pair, not one by one
(defun diff1 (lst)
    (if lst
        (and (= (abs (- (car lst) (nth 1 lst))) 1) (diff1 (cdr (cdr lst))))
        t))

;repetition

(defun diff1 (lst)
    (let ((fst (car lst)))
        (dolist (sec (cdr lst) t)
            (if (= 1 (abs (- fst sec)))
                (setf fst sec)
                (return-from diff1 nil)))))


;b
;do

(defun diff1 (lst)
    (do ((l lst (cdr l))
         (fst (car lst) (car l))
         (sec (nth 1 lst) (nth 1 l)))
        ((not (cdr l)) t)
        (if (/= 1 (abs (- fst sec)))
            (return-from diff1 nil))))
         
(defun diff1 (lst)
    (do ((l (cdr lst) (cdr l))
         (fst (car lst) (car l)))
        ((not l) t)
        (if (/= 1 (abs (- fst (car l))))
            (return nil))))

;c
;mapc return

(defun diff1 (lst)
    (mapc #'(lambda (x y) (if (/= 1 (abs (- x y))) (return-from diff1 nil))) lst (cdr lst))
    t)

;5.8

(defun max_min (lst)
    (let ((maxv (car lst))
          (minv (car lst)))
         (max_min-rec maxv minv (cdr lst))))

(defun max_min-rec (maxv minv lst)
    (if lst
        (let ((obj (car lst)))
            (if (< maxv obj)
                (setf maxv obj))
            (if (< obj minv)
                (setf minv obj))
            (max_min-rec maxv minv (cdr lst)))
        (values maxv minv)))

; simple version
(defun max_min (lst)
    (max_min-rec (car lst) (car lst) (cdr lst)))

(defun max_min-rec (maxv minv lst)
    (if lst
        (let ((o (car lst)))
            (max_min-rec (if (< maxv o) o maxv) (if (< o minv) o minv) (cdr lst)))
        (values maxv minv)))

;5.9
;a
(setf min '((a b c) (b c) (c d)))

(defun shortest-path (start end net)
  (catch 'find
    (bfs end (list (list start)) net)))

(defun bfs (end queue net)
  (if (null queue)
      nil
      (let ((path (car queue)))
        (let ((node (car path)))
          (if (eql node end)
              (throw 'find (reverse path))
              (bfs end
                   (append (cdr queue)
                           (new-paths path node net))
                   net))))))

(defun new-paths (path node net)
  (mapcar #'(lambda (n)
              (cons n path))
          (cdr (assoc node net))))

;b

(defun shortest-path (start end net)
  (bfs end (list (list start)) net))

(defun bfs (end queue net)
  (if (null queue)
      nil
      (let ((path (car queue)))
        (let ((node (car path)))
          (if (eql node end)
              (reverse path)
              (bfs end
                   (append (cdr queue)
                           (new-paths path node net))
                   net))))))

(defun new-paths (path node net)
  (mapcar #'(lambda (n)
              (cons n path))
          (cdr (assoc node net))))
