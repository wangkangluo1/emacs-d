(defun no-e-please ()                                                                                                                                                            
         (interactive)
;		 (message "Please don't use the letter e")
		 ;(message point-marker)
	      )
 (provide 'test)
 

(defun oowrite-table-convert (col beg end)
  "删除回车"
 (interactive "nColumns of table: \nr")
 (setq col (1- col))
 (save-excursion
  (save-restriction
   (narrow-to-region beg end)
   (goto-char (point-min))
   (while (not (eobp))
	   (dotimes (i col)
		(forward-line 1)
		(backward-delete-char 1)
		(insert-char ?\t 1))
	   (forward-line 1)))))

(defun my-directory-all-files (dir &optional full match nosort)
  (interactive)
  (apply 'append
		 (delq nil
			   (mapcar
				(lambda (file)
				  (if (and (not (string-match "^[.]+$" (file-name-nondirectory file)))
						   (file-directory-p (expand-file-name file dir)))
					  (if full
						  (my-directory-all-files file full match nosort)
						(mapcar (lambda (f)
								  (concat (file-name-as-directory file) f))
								(my-directory-all-files (expand-file-name file dir)
														full match nosort)))
					(if (string-match match file)
						(list file))))
				     (directory-files dir full nil nosort)))))

(defun add-to-my-global
  (interactive)
  (write-region "~/fuckdown"))




