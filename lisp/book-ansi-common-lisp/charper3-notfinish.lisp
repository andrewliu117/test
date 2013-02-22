;;;; "ansi common lisp" charper3 quiz

;2.2

(defun new-union (x y)
    (dolist (obj y)
        (if (null (intersection x (list obj)))
            (setf x (append x (list obj)))))
    x)

