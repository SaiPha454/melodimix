#include "importfolder.h"
#include <QCoreApplication>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QFileDialog>
#include <QStringList>

void ImportFolder::create(const QString foldername) {

    QString deskoplocation = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir desktopDir(deskoplocation);

    if(!desktopDir.exists(foldername)) {
        desktopDir.mkdir(foldername);
    }else{
        qDebug() <<"FOlder already exists"<<desktopDir.filePath(foldername);
    }
}


QStringList ImportFolder::import() {

    QStringList filePaths = QFileDialog::getOpenFileNames(nullptr, "Select MP3 Files", QDir::homePath(), "MP3 Files (*.mp3);;All Files (*)");
    QString desktopLocation = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir desktopDir(desktopLocation);
    QStringList importedFiles;

    if (!filePaths.isEmpty()) {
        QString destinationFolder = desktopDir.filePath("MelodiMix");

        for (const QString &filePath : filePaths) {

            QString filename = QFileInfo(filePath).fileName();
            QString destination = destinationFolder + QDir::separator() + filename;

            if (QFile::copy(filePath, destination)) {
                importedFiles.push_back(filename);
                qDebug() << "Successfully copied" << filename;
            } else {
                qDebug() << "Failed to copy" << filename;
            }
        }
    } else {
        qDebug() << "No selected files";
    }

    return importedFiles;

}

QStringList ImportFolder::load() {

    QString desktopLocation = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir desktopDir(desktopLocation);
    QString folderPath = desktopDir.filePath("MelodiMix");
    QDir folder(folderPath);

    return folder.entryList(QDir::Files);
}


QString ImportFolder::getHomePath(){

    QString desktopLocation = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QDir desktopDir(desktopLocation);
    return desktopDir.filePath("MelodiMix");
}

void ImportFolder::removeFile(QString filename) {

    QString filepath = ImportFolder::getHomePath() + "/"+filename;
    QFile file(filepath);
    if (file.exists()) {
        if (file.remove()) {
            qDebug() << "File removed successfully";
        } else {
            qDebug() << "Error removing file:" << file.errorString();
        }
    } else {
        qDebug() << "File does not exist.";
    }
}
