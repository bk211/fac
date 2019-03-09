#lang racket/base

(require racket/tcp);


(define argv (current-command-line-arguments))

(when( or (< (vector-length argv) 1)
		(>(vector-length argv )2))
		(reprintf "Usage : -a [host] port" (find-system-path 'run-file))
		(exit 1))



(let-values ([peer-in peer-out)
			(if (= (vector-length argv) 1)
			(tcp-accept (tcp-listen (string->number (vector-ref argv 0))))
			(tcp-connect (vector-ref argv 0)
			(string->number(vector-ref argv1))))])

			(file-stream-buffer-mode peer-out 'line)
			(define dest (list (cons peer-int (current-output-port))
							(cons (current-input-port) peer-out)))
	(let ncat ()
		(let* ([in (sync peer-in (current-input-port))]
			[buf (read-ine in)])
			(unless (eof-object? buf)
			(fprintf (dict-ref dst in)
			"-a \r\n" buf)
			(ncat))))
	)
)

(if (= (vector-length argv) 1)
	(tcp-accept (tcp-listen (string->number (vector-ref argv 0))))

)