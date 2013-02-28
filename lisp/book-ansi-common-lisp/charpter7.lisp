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
