#include <QCoreApplication>
#include <QDir>

#include "httplistener.h"
#include "httprequesthandler.h"



/**
 * Search the configuration file.
 * Aborts the application if not found.
 * @return The valid filename
 */
QString searchConfigFile() {
    QString binDir=QCoreApplication::applicationDirPath();
    QString appName=QCoreApplication::applicationName();
    QFile file;
    file.setFileName(binDir+"/webapp1.ini");
    if (!file.exists()) {
        file.setFileName(binDir+"/etc/webapp1.ini");
        if (!file.exists()) {
            file.setFileName(binDir+"/../etc/webapp1.ini");
            if (!file.exists()) {
                file.setFileName(binDir+"/../"+appName+"/etc/webapp1.ini");
                if (!file.exists()) {
                    file.setFileName(binDir+"/../../"+appName+"/etc/webapp1.ini");
                    if (!file.exists()) {
                        file.setFileName(binDir+"/../../../../../"+appName+"/etc/webapp1.ini");
                        if (!file.exists()) {
                            file.setFileName(QDir::rootPath()+"etc/webapp1.ini");
                        }
                    }
                }
            }
        }
    }
    if (file.exists()) {
        QString configFileName=QDir(file.fileName()).canonicalPath();
        qDebug("using config file %s", qPrintable(configFileName));
        return configFileName;
    }
    else {
        qFatal("config file not found");
    }
}


int main(int argc, char *argv[])
{
    // 最好不用 QApplication (带界面 这样不好 利用qtservice 部署成服务 )
    QCoreApplication app(argc, argv);

    // Load the configuration file
    QString configFileName=searchConfigFile();
    QSettings* listenerSettings=new QSettings(configFileName, QSettings::IniFormat, &app);
    listenerSettings->beginGroup("listener");

    // Start the HTTP server
    new stefanfrings::HttpListener(listenerSettings, new stefanfrings::HttpRequestHandler(&app), &app);

    return app.exec();
}
