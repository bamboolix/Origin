#include "mainwindow.h"
#include <QApplication>
#include <QProcess>

/**
 * \file main.cpp
 * \brief Origin est une application qui détecte un tag NFC ouvre chromium-browser en lui transmettant des paramètres de la puce.
 * \author Namboka David et Olivier Levasseur
 * \version 0.1
 * \date 22 octobre 2016
 *
 * Application de détection du signal envoyé par le lecteur NFC RC522, déclenchement du process chromium-browser
 *
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*
     *  Prérequis : Install Raspberry Pi 3 Jessie distribution : https://www.raspberrypi.org/downloads/ choose Raspbian either using NOOBS or raw installation.
                    Install Chromium-browser ( supports WebGL unlike native Raspberry browser ).

                    wget https://launchpad.net/~canonical-chromium-builds/+archive/ubuntu/stage/+build/7916060/+files/chromium-browser_45.0.2454.85-0ubuntu0.15.04.1.1181_armhf.deb
                    wget https://launchpad.net/~canonical-chromium-builds/+archive/ubuntu/stage/+build/7916060/+files/chromium-codecs-ffmpeg-extra_45.0.2454.85-0ubuntu0.15.04.1.1181_armhf.deb
                    sudo dpkg -i chromium-codecs-ffmpeg-extra_45.0.2454.85–0ubuntu0.15.04.1.1181_armhf.deb chromium-browser_45.0.2454.85–0ubuntu0.15.04.1.1181_armhf.deb

                    Check Markdown Git file for complete installation process

     */
    // Launch chromium-browser with arguments url and fullscreen mode
    QObject *parent = new QObject();
    QString program = "chromium-browser";
    QStringList arguments;

    arguments << "--kiosk" << "http://www.free.fr";
    QProcess *myProcess = new QProcess( parent );
    myProcess -> start( program, arguments );

    w.show();
    return a.exec();
}
