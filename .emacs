



(setq load-path (cons "~/.emacs.d/" load-path))   ;配置.el文件位置 
(require 'xcscope)

(require 'multi-term)   ;shell多窗口
(setq multi-term-program "/bin/bash")

(add-to-list 'load-path "~/.emacs.d/msf-abbrevs/mode-abbrevs/global/el")
(require 'test)       
(add-to-list 'load-path "~/.emacs.d/msf-abbrevs/mode-abbrevs/global/el/color-theme-6.6.0")
(require 'color-theme)

(require 'php-mode)
    ;;根据文件扩展名自动php-mode
; (add-to-list 'auto-mode-alist '("\\.php[34]?\\'\\|\\.phtml\\'" . php-mode)  )


;;;;auto-complete代码自动补充
;(add-to-list 'load-path "~/.emacs.d")
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/ac-dict")
(ac-config-default)

;;;;javascript--------------------------------------------------------------------------------------------------------------------------------
(autoload 'js2-mode "js2" nil t)
(add-to-list 'auto-mode-alist '("\\.js$" . js2-mode))

(autoload 'javascript-mode "javascript" nil t)
(add-to-list 'auto-mode-alist '("\\.js\\'" . javascript-mode))
;------------------------------------------------------------------------------------------------------------------------------------------------

;;;;cedet----------------------------------------------------------------------------------------------------------------------------------
(load-file "~/.emacs.d/cedet-1.0pre7/common/cedet.elc")
(global-ede-mode 1)
(semantic-load-enable-gaudy-code-helpers)
(global-srecode-minor-mode 1)
;------------------------------------------------------------------------------------------------------------------------------------------

;;;;ecb---------------------------------------------------------------------------------------------------------------------------------------
(add-to-list 'load-path
                     "~/.emacs.d/ecb-2.40")
(require 'ecb)
(require 'ecb-autoloads)
;--------------------------------------------------------------------------------------------------------------------------------------------




;;;;F快捷键设置
										;(global-set-key(kbd "<f2>")   'other-window)   ;切换到其他窗口
(global-set-key(kbd "<f2>")   'gdb-many-windows)   ;gdb多窗口模式
(global-set-key(kbd "<f3>")   'eassist-switch-h-cpp)   ;h/cpp切换
(global-set-key(kbd "<f4>")   'delete-window)   ;关闭当前窗口


(global-set-key(kbd "<f5>")   'revert-buffer)   ;更新文件
(global-set-key(kbd "<f6>")   'global-linum-mode)   ;显示行号 (global-linum-mode t) 或者m-x global-linum-mode回车 就可以显示行号
(global-set-key (kbd "<f7>") 'ecb-minor-mode)   ; 打开ejb

;(global-set-key (kbd "<f8>") 'semantic-mrub-switch-tags)   ; 返回跳转来的地
;(global-set-key (kbd "<f8>") 'cscope-find-global-definition)   ; 跳转到函数定义的地方
 ;(global-set-key(kbd "<f9>")   'semantic-ia-fast-jump)   ;跳转到函数定义的地方
(global-set-key (kbd "<f8>") 'advertised-undo)   ; 返回上一步


(global-set-key (kbd "<f12>") 'semantic-symref)   ; 查看在哪些地方使用了

;(global-set-key(kbd "<f6>")   'other-window)   ;切换到其他窗口
;(global-set-key(kbd "M-3")   'eassist-switch-h-cpp)   ;h/cpp切换
;(global-set-key(kbd "M-4")   'semantic-ia-fast-jump)   ;跳转到函数定义的地方
;(global-set-key(kbd "M-5")   'global-linum-mode)   ;显示行号 (global-linum-mode t) 或者m-x global-linum-mode回车 就可以显示行号
;(global-set-key(kbd "M-6")   'gdb-many-windows)   ;gdb多窗口模式
;(global-set-key (kbd "M-7") 'ecb-minor-mode)   ; 打开ejb
;(global-set-key (kbd "M-8") 'semantic-mrub-switch-tags)   ; 返回跳转来的地
;(global-set-key(kbd "M-9")   'delete-window)   ;关闭当前窗口
;(global-set-key (kbd "M-0") 'semantic-symref)   ; 查看在哪些地方使用了



;;;;窗口大小调节
(global-set-key (kbd "M-<left>") 'shrink-window-horizontally)   ; 水平缩小窗口
(global-set-key (kbd "M-<right>") 'enlarge-window-horizontally)  ; 水平扩大窗口
(global-set-key (kbd "M-<up>") 'balance-windows)     ; 平衡所有窗口
(global-set-key (kbd "M-<down>") 'enlarge-window)   ; 垂直扩大窗口
(global-set-key (kbd "C-l") 'goto-line)   ; 跳转到行




;;;;分割窗口
;(global-set-key(kbd "C-S")   'split-window-vertically)   ;垂直分割窗口
;(global-set-key(kbd "C-A")   'split-window-horizontally)   ;水平分割窗口




;;;;ejb 快捷键
(global-set-key (kbd "C-<left>") 'windmove-left)   ;左边窗口
(global-set-key (kbd "C-<right>") 'windmove-right)  ;右边窗口
(global-set-key (kbd "C-<up>") 'windmove-up)     ; 上边窗口
(global-set-key (kbd "C-<down>") 'windmove-down)   ; 下边窗口


(global-set-key (kbd "C-f") 'cscope-find-this-text-string)   ; 查找字符串



;缩进-------------------------------------------------------------------------------------------------------------------------------------------
;;设置TAB宽度为4
(setq default-tab-width 4) 
;;以下设置缩进 
(setq c-indent-level 4)
(setq c-continued-statement-offset 4)
(setq c-brace-offset -4) 
(setq c-argdecl-indent 4)
(setq c-label-offset -4)
(setq c-basic-offset 4) 
(global-set-key "\C-m" 'reindent-then-newline-and-indent) 
(setq indent-tabs-mode nil)
(setq standard-indent 4)



;;不产生备份文件 
(setq make-backup-files nil)





(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(ecb-options-version "2.40"))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )


;msf-abbrevs系统----------------------------------------------------------------------------------------------------------------------------------------------
(add-to-list 'load-path "~/.emacs.d/msf-abbrevs")

;; ensure abbrev mode is always on
(setq-default abbrev-mode t)

;; do not bug me about saving my abbreviations
(setq save-abbrevs nil)

;; load up modes I use
;(require 'muse-mode)
(require 'cc-mode)
;(require 'muse-mode)

;; load up abbrevs for these modes
(require 'msf-abbrev)
(setq msf-abbrev-root "~/.emacs.d/msf-abbrevs/mode-abbrevs")

(msf-abbrev-load)

;; use C-c a to define a new abbrev for this mode
(global-set-key (kbd "C-c a") 'msf-abbrev-define-new-abbrev-this-mode)

;--------------------------------------------------------------------------------------------------------------------------------------------------------





;.c文件自动载入模板-------------------------------------------------------------------------------------------------------------------------------------------
(require 'tempo)

(setq c-new-buffer-template 
      '(
 ;       "#include <stdio.h>\n"
  ;      "#include <stdlib.h>\n"
   ;     "\n"
    ;    "int main(void){\n"
     ;   "\n"
      ;  "}\n"
       ; ))
"/*\n"
" * =====================================================================================\n"
" *\n"
" *       Filename:  test.c\n"
" *\n"
" *    Description:\n"
" *\n"
" *        Version:  1.0\n"
" *        Created:  07/29/2011 10:37:04 AM\n"
" *       Revision:  none\n"
" *       Compiler:  gcc\n"
" *\n"
" *         Author:  kangle.wang (mn), wangkangluo1@gmail.com\n"
" *        Company:  APE-TECH\n"
" *\n"
" * =====================================================================================\n"
" */\n"
))

(defun my-c-style ()
  "My editing style for .c files."
  (c-mode)
  (if (zerop (buffer-size))
      (tempo-template-c-skeleton)))

(setq auto-mode-alist
      (cons '("\\.c\\'" . my-c-style) auto-mode-alist))

(tempo-define-template "c-skeleton" c-new-buffer-template
               nil
               "Insert a skeleton for a .c document")
;---------------------------------------------------------------------------------------------------------------------------------------------------




;实验-------------------------------------------------------------------------------------------------------------------------------------------------
;(defun hello-world (name)
;  "Say hello to user whose name is NAME."
;  (message "Hello, %s" name))
;(hello-world "fuckof")
;

;(defun no-e-please ()
;         (interactive)
;  (message "Please don't use the letter e"))

(global-set-key (kbd "C-e") 'no-e-please)
;--------------------------------------------------------------------------------------------------------------------------------------------------------

;dont


;;;; 当输入"."或">"时，在另一个窗口中列出结构体或类的成员
(defun my-c-mode-cedet-hook ()
  (local-set-key "." 'semantic-complete-self-insert)
  (local-set-key ">" 'semantic-complete-self-insert))
(add-hook 'c-mode-common-hook 'my-c-mode-cedet-hook)
