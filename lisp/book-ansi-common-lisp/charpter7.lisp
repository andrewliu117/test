;7.1

(defun readfile (file)
    (let (acc)
        (with-open-file (str file :direction :input)
            (do ((line (read-line str nil 'eof) (read-line str nil 'eof)))
                ((eql line 'eof))
                (push line acc)))
        (nreverse acc)))

;7.2

(defun readfile (file)
    (with-open-file (str file :direction :input)
        (do ((line (read str nil nil) (read str nil nil))
             (acc nil (push line acc)))
            ((not line) (nreverse acc)))))

;7.3

; a buggy one
(defun copyfile (s d)
    (with-open-file (ss s :direction :input)
        (with-open-file (ds d :direction :output :if-exists :supersede)
            (do ((line (read-line ss nil nil) (read-line ss nil nil)))
                ((not line)(format t "Copy file done!~%"))
                (if (eql (aref line 0) #\%) nil (format ds "~a~%" line))))))

(defun copyfile (s d &optional (cchar #\%))
    (with-open-file (ss s :direction :input)
        (with-open-file (ds d :direction :output :if-exists :supersede)
            (do ((line (read-line ss nil nil) (read-line ss nil nil)))
                ((not line)(format t "Copy file done!~%"))
                (let ((cp (position cchar line)))
                    (format ds "~a~%" (if cp (subseq line 0 cp) line)))))))
;7.4

(defun pfarr (farr)
   (let ((n (first (array-dimensions farr))) 
         (m (second (array-dimensions farr))))
        (do ((i 0 (+ i 1)))
            ((= i n))
            (do ((j 0 (+ j 1)))
                ((= j m))
                (format t "~10,2,,,' F~%" (aref farr i j))))))

(defun pfarr (farr)
    (let ((size (array-dimensions farr)))
        (dotimes (i (first size))
            (dotimes ( j (second size))
                (format t "~10,2F~%" (aref farr i j))))))

;7.5
;(cond (or (char= c (char old pos)) (char= #\+ (char old pos)))
;    ...)

;7.6
; not finished
