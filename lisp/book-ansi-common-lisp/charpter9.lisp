;9.1

(defun nondecreasing (lst)
    (not (apply #'>= ls)))

;9.2

(defun divide_cent (cents)
    (setf q (round (/ cents 25)))
    (setf cents (mod cents 25))
    (setf ten (round (/ cents 10)))
    (setf cents (mod cents 10))
    (setf five (round (/ cents 5)))
    (setf one (mod cents 10))
    (format t "~a ~a ~a ~a ~%" q ten five one)) 
