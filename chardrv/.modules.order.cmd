cmd_/home/karnex/logesh/chardrv/modules.order := {   echo /home/karnex/logesh/chardrv/char_drv.ko; :; } | awk '!x[$$0]++' - > /home/karnex/logesh/chardrv/modules.order
