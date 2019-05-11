#include <QFile>
#include <QTemporaryDir>
#include <QTime>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QFile srcFile("/Users/Christian/Downloads/Windows10_x64.iso");
    out << "Source existiert: " << (srcFile.exists() ? "true" : "false") << endl;
    QTime startTime = QTime::currentTime();
    QTemporaryDir tempDir;
    QString destFilePath = tempDir.filePath("kaspersky.iso");
    if (srcFile.copy(destFilePath))
    {
        QFile destFile(destFilePath);
        if (destFile.rename("/Users/Christian/copy.iso"))
        {
            out << "File umbenannt: " << destFile.fileName() << endl;
        }
    }
    else
    {
        out << "Fehler File nicht kopiert !!!" << endl;
    }
    QTime endTime = QTime::currentTime();
    QString format("hh:mm:ss");

    out << "Start: " << startTime.toString(format) << '\n';
    out << "End:   " << endTime.toString(format) << endl;

    return 0;
}
