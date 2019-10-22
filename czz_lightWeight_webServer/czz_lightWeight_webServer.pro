QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# QtWebApp 一个强大的轻量 Web Server服务器
# If you have ever developed web server applications with the Java Servlet API, you will feel like at home.
# My library provides almost the same functionality. I will show you how to write a minimal web server application with QtWebApp.
# Then we will discover the main features step by step.

# 关于该库的具体信息 Api instruction  , usage  ,demo   See below
# http://www.stefanfrings.de/qtwebapp/tutorial/index.html

# 这里我会引入该库 的 所有 pri 子工程 : 子工程的作用为何 详见官网
include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/QtWebApp/logging/logging.pri)
include(../QtWebApp/QtWebApp/qtservice/qtservice.pri)
include(../QtWebApp/QtWebApp/templateengine/templateengine.pri)



SOURCES += \
        src/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    etc/webapp1.ini
