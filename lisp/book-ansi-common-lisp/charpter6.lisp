;6.1

;(defun tokens (str &key (test #' constituent) (start 0))
;   ...)

;6.2

;(defun bin-search (obj vec &optional (start 0) (end (- (length vec) 1)) &key (key #' identity) (test #'eql))
;   ...)

;6.3

(defun args (&rest rargs)
     rargs)

;6.4

;have bug
(defun most (fn lst)
  (if (null lst)
      (values nil nil)
      (if (not (cdr lst))
          (values (car lst) nil)
          (let* ((wins1 (car lst))
                 (max1 (funcall fn wins1))
                 (wins2 (nth 1 lst))
                 (max2 (funcall fn wins2)))
            (dolist (obj (cdr (cdr lst)))
              (let ((score (funcall fn obj)))
                (if (> score max1)
                  (setf wins2 wins1 max2 max1  wins1 obj max1  score)
                  (if (> score max2)
                    (setf wins2 obj max2 score)))))
            (values wins1 wins2)))))

(defun most (fn lst)
    (cond ((not lst) (values nil nil))
          ((not (cdr lst)) (values (car lst) nil))
          (t
             (let* ((wins1 (first lst))
                    (max1 (funcall fn wins1))
                    (wins2 (second lst))
                    (max2 (funcall fn wins2)))
                 (when (< max1 max2)
                    (rotatef max1 max2)
                    (rotatef wins1 wins2))
                 (dolist (obj (nthcdr 2 lst))
                   (let ((score (funcall fn obj)))
                        (cond 
                            ((< max1 score) (setf wins2 wins1 max2 max1  wins1 obj max1  score))
                            ((< max2 score) (setf wins2 obj max2 score))
                            (t nil))))
                 (values wins1 wins2)))))
            

;6.5

(defun filter (fn lst)
  (let ((acc nil))
    (dolist (x lst)
      (let ((val (funcall fn x)))
        (if val (push val acc))))
    (nreverse acc)))

(defun myremove-if (fn lst)
    (filter #'(lambda (x) (if (funcall fn x) nil x)) lst)) 

;6.6

(let (mx)
    (defun max-so-far(x)
        (if (or (not mx) (< mx x))
            (setf mx x))
        mx))

;6.7

(let (pre)
    (defun max-pre?(n)
        (setf ppre pre pre n)
        (if (or (not ppre) (< pre ppre))
            nil
            t)))

(let (prev)
    (defun greater-p (n)
        (prog1
            (and prev (< prev n))
            (setf prev n))))

;6.8

(let ((ht (make-hash-table)))
    (defun frugal (n)
        (setf htv (gethash n ht))
        (if (not htv)
            (let ((v (expensive n)))
                (setf (gethash n ht) v)
                v)
            htv)))

(let ((ht (make-hash-table)))
    (defun frugal (n)
        (or (gethash n ht)
            (setf (gethash n ht) (expensive n)))))

(defun expensive (n)
    (do ((i 0 (+ i 1)))
        ((= i 1000000) (* n n))
        (/ 23152341234 12314214)))

;6.9

(defun myapply(&rest args)
    (let ((*print-base* 8))
        (apply #'apply args)))
