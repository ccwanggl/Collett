/*
** Collett – Core Storage Class
** ============================
**
** This file is a part of Collett
** Copyright 2020–2024, Veronica Berglyd Olsen
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include "storage.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

namespace Collett {

Storage::Storage(const QString &path, bool compact) : m_compactJson(compact)
{
    QFileInfo pathInfo(path);
    if (pathInfo.suffix().toLower() == "fcollett") {
        m_saveMode = Storage::Flat;
        m_isValid = pathInfo.isWritable();
    } else if (pathInfo.suffix().toLower() == "collett") {
        m_saveMode = Storage::Archive;
        m_isValid = pathInfo.isWritable();
    } else {
        m_lastError = "Archive storage is not yet implemented";
        m_saveMode = Storage::Archive;
        m_isValid = false;
        qWarning() << "Invalid path:" << path;
    }
    if (m_isValid) {
        m_rootPath = QDir(QDir(path).absolutePath());
    } else {
        m_rootPath = QDir();
    }

    qDebug() << "Root Path:" << m_rootPath.path();
};

Storage::~Storage() {
    qDebug() << "Destructor: Storage";
};

/**
 * Class Methods
 */

bool Storage::readProject(QJsonObject &fileData) {

    if (!m_isValid) {
        return false;
    }

    if (m_saveMode == Mode::Flat) {
        return this->readJson(m_rootPath.path(), fileData);
    }

    return false;
}

bool Storage::writeProject(const QJsonObject &fileData) {

    if (!m_isValid) {
        return false;
    }

    if (m_saveMode == Mode::Flat) {
        return this->writeJson(m_rootPath.path(), fileData, false);
    }

    return false;
}

bool Storage::isValid() {
    return m_isValid;
}

QString Storage::projectPath() const {
    if (m_isValid) {
        return m_rootPath.path();
    } else {
        return QString();
    }
}

bool Storage::hasError() {
    return !m_lastError.isEmpty();
}

QString Storage::lastError() const {
    return m_lastError;
}

/**
 * Static Methods
 */

/**!
 * @brief Get string from JSON object.
 *
 * @param object the json object.
 * @param key    the key of the value to look up.
 * @param def    the default value to return in case the key does not exist.
 * @return the value or the default as a string.
 */
QString Storage::getJsonString(const QJsonObject &object, const QLatin1String &key, QString def) {
    if (object.contains(key)) {
        return object.value(key).toString();
    } else {
        return def;
    }
}

/**
 * Private Methods
 */

bool Storage::readJson(const QString &filePath, QJsonObject &fileData) {

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        m_lastError = tr("Could not open file: %1").arg(filePath);
        qWarning() << "Could not open file:" << filePath;
        return false;
    }

    QJsonParseError *error = new QJsonParseError();
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(), error);
    if (error->error != QJsonParseError::NoError) {
        m_lastError = tr("Could not parse file: %1").arg(filePath);
        qWarning() << "Could not parse file:" << filePath;
        qWarning() << error->errorString();
        return false;
    }

    if (!json.isObject()) {
        m_lastError = tr("Unexpected content of file: %1").arg(filePath);
        qWarning() << "Unexpected content of file:" << filePath;
        return false;
    }

    fileData = json.object();
    qDebug() << "Read:" << filePath;

    return true;
}

bool Storage::writeJson(const QString &filePath, const QJsonObject &fileData, bool compact) {

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        m_lastError = tr("Could not open file: %1").arg(filePath);
        qWarning() << "Could not open file:" << filePath;
        return false;
    }

    QJsonDocument doc(fileData);
    QByteArray jsonData = doc.toJson(m_compactJson ? QJsonDocument::Compact : QJsonDocument::Indented);

    if (compact) {
        file.write(jsonData);
    } else {
        for (QByteArray line: jsonData.split('\n')) {
            QByteArray trimmed = line.trimmed();
            if (trimmed.length() > 0) {
                file.write(QByteArray((line.length() - trimmed.length())/4, '\t') + trimmed + '\n');
            }
        }
    }
    file.close();
    qDebug() << "Wrote:" << filePath;

    return true;
}

} // namespace Collett
