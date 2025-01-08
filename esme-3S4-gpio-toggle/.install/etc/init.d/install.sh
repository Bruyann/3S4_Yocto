#!/bin/sh
### BEGIN INIT INFO
# Provides:             esme-gpio26-toggle
# Required-Start:       $remote_fs $time
# Required-Stop:        $remote_fs $time
# Default-Start:        3 4 5
# Default-Stop:         0 1 2 6
# Short-Description:    ESME GPIO#26 toggle service
### END INIT INFO

BIN="/usr/bin/esme-gpio-toggle"
GPIO=26

case "$1" in
    start)
        start-stop-daemon --start --background --exec $BIN -- --gpio $GPIO
        ;;
    stop)
        start-stop-daemon --stop --exec $BIN
        ;;
    restart)
        $0 stop
        $0 start
        ;;
    status)
        pidof $BIN > /dev/null && echo "Running with PID=$(pidof $BIN)" || echo "Stopped"
        ;;
    *)
        echo "Usage: $0 (start | stop | restart | status)"
        exit 1
        ;;
esac
