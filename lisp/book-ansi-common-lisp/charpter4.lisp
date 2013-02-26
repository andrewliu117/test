;4.1

; a simple transposition for multi array
(defun quarter-trans (arr)
    (setf dim (array-dimensions arr))
    (let ((barr (make-array dim))) 
        (do ((i 0 (+ i 1)))
            ((= i (car dim)))
            (do ((j 0 (+ j 1)))
                ((= j (car dim)))
                (setf (aref barr i j) (aref arr j i))))
        barr))

; wrong, in "(barr (make-array dim1))" don't kown what's dim1
;(defun quarter-turn (arr)
;    (let ((dim1 (array-dimensions arr))
;          (barr (make-array dim1))) 
;        (do ((i 0 (+ i 1)))
;            ((= i (car dim)))
;            (do ((j 0 (+ j 1)))
;                ((= j (car dim)))
;                (setf (aref barr i j) (aref arr j i))))
;        barr))

; from book, wrong, anticlockwise
(defun quarter-turn (arr)
    (setf dim (array-dimensions arr))
    (let ((d (car dim))
          (barr (make-array dim))) 
        (let ((c (/ (- d 1) 2))) 
            (do ((i 0 (+ i 1))) ((= i (car dim)))
                (do ((j 0 (+ j 1))) ((= j (car dim)))
                    (setf (aref barr (+ (* -1 (- j c)) c) i) (aref arr i j)))))
        barr))

; right one, clockwise
(defun quarter-turn (arr)
    (setf dim (array-dimensions arr))
    (let ((d (car dim))
          (barr (make-array dim))) 
        (do ((i 0 (+ i 1))) ((= i d))
            (do ((j 0 (+ j 1))) ((= j d))
                (setf (aref barr j (- (- d 1) i)) (aref arr i j))))
        barr))

;4.2

(defun mycopy-list (lst)
    (reduce #'(lambda (x n) 
                (if (listp x)
                    (append x (list n))
                    (list x n)))
            lst))

(defun mycopy-list (lst)
    (reduce #' cons lst :from-end t :initial-value nil))

(defun myreverse (lst)
    (reduce #' (lambda (x n) (cons n x)) lst :initial-value nil))

;4.3

(defstruct tnode 
    (elt 0) (l nil) (m nil) (r nil))

;a
(defun copy-mytree (tn)
    (if tn
        (let ((new (make-tnode :elt (tnode-elt tn))))
            (copy-node new tn)
            new)
        nil))

(defun copy-node (new old)
    (if (tnode-l old)
        (let (((tnode-l new) (make-tnode :elt (tnode-elt (tnode-l old)))))
            (copy-node (tnode-l new) (tnode-r old))))
    (if (tnode-m old)
        (let (((tnode-m new) (make-tnode :elt (tnode-elt (tnode-m old)))))
            (copy-node (tnode-m new) (tnode-m old))))
    (if (tnode-r old)
        (let (((tnode-r new) (make-tnode :elt (tnode-elt (tnode-r old)))))
            (copy-node (tnode-r new) (tnode-r old))))

(defun copy-mytree (tn)
    (if tn
        (make-tnode :elt (tnode-elt tn)
                    :l (copy-mytree (tnode-l tn))
                    :m (copy-mytree (tnode-m tn))
                    :r (copy-mytree (tnode-r tn)))))

;b
(defun find-n (obj tn)
    (if tn
        (or (eql obj (tnode-elt tn))
            (find-n obj (tnode-l tn))
            (find-n obj (tnode-m tn))
            (find-n obj (tnode-r tn)))))

;4.4

(defstruct node elt (r nil) (l nil))
(setf root (make-node :elt 3))
(setf (node-l root) (make-node :elt 2))
(setf (node-r root) (make-node :elt 6))
(setf (node-l (node-r root)) (make-node :elt 5))
(setf (node-r (node-r root)) (make-node :elt 7))

(defun list-t (n)
    (if n
        (append (list-t (node-l n)) (list (node-elt n)) (list-t (node-r n)))))

;4.5
(defun bst-insert (obj bst cmp-fn)        
    (if bst
        (let ((elt (node-elt bst)))
            (if (eql obj elt)
                elt
                (if (funcall cmp-fn obj elt)
                    (if (null (node-l bst))
                        (setf (node-l bst) (make-node :elt obj))
                        (bst-insert obj (node-l bst) cmp-fn))
                    (if (null (node-r bst))
                        (setf (node-r bst) (make-node :elt obj))
                        (bst-insert obj (node-r bst) cmp-fn)))))
        (make-node :elt obj)))

;4.6

(setf acc '((A . 1) (B . 2) (C . 3)))

(defun assoc2hase (acc &key (test #' eql))
    (let ((ht (make-hash-table :test test)))
        (dolist (obj acc)
            (setf (gethash (car obj) ht) (cdr obj)))
        ht))

(setf myht (assoc2hase acc))
(maphash #'(lambda (k v)
            (format t "~A = ~A~%" k v))
        myht)

;b

(setf ht (make-hash-table))
(setf (gethash 'a ht) 1)
(setf (gethash 'b ht) 2)
(setf (gethash 'c ht) 3)

(maphash #'(lambda (k v)
            (format t "~A = ~A~%" k v))
        ht)

(defun hash2assoc (ht)
    (let ((acc nil))
        (maphash #' (lambda (k v) (push (cons k v) acc)) ht)
        acc))
