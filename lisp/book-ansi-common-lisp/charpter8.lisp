;8.4

; add this at the beginning of the file
(defpackage "ring" (:use "COMMON-LISP") (:export "BUF" "BREF" "NEW-BUF" "BUF-INSERT" "BUF-POP" "BUF-NEXT" "BUF-RESET" "BUF-CLEAR" "BUF-FLUSH")
(in-package ring)

(defpackage "file" (:use "COMMON-LISP") (:export "file-subst"))
(in-package file)

;8.5

; concatenate
(dolist (obj (concatenate 'list "abcdefg"))
    (format t "~a~%" obj))

; wrong
;(dolist (obj "abcdefg")
;    (format t "~a~%" obj))

;another way
(do ((i 0 (1+ i)))
    ((>= i (length "abcdefg")))
    (format t "~a~%" (aref "abcdefg" i)))

(defun byhelenly (str)
    (do ((i 0 (1+ i)))
        ((>= i (length str)) t)
        (let ((c (aref str i)))
            (if (or (alpha-char-p c) (char= c #\'))
                (progn
                    (setf (aref buffer pos) c)
                    (incf pos))
                (progn
                    (unless (zerop pos)
                        (unless (check (intern (string-downcase
                                   (subseq buffer 0 pos))))
                            (return-from byhelenly nil))
                        (setf pos 0))
                    (let ((p (punc c)))
                        (if p (unless (check p) (return-from byhelenly nil)))))))))

(let ((prev `|.|))
    (defun check (symb)
        (let ((pair (assoc symb (gethash prev *words*))))
            (if pair
                t
                nil)
            (setf prev symb))))

