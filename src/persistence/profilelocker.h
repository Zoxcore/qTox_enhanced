/*
    Copyright © 2015-2019 by The qTox Project Contributors

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once

#include <QLockFile>
#include <memory>

class Paths;

class ProfileLocker
{
private:
    ProfileLocker() = delete;

public:
    static bool isLockable(QString profile, Paths& paths);
    static bool lock(QString profile, Paths& paths);
    static void unlock();
    static bool hasLock();
    static QString getCurLockName();
    static void assertLock(Paths& paths);

private:
    static QString lockPathFromName(const QString& name, const Paths& paths);
    static void deathByBrokenLock();

private:
    static std::unique_ptr<QLockFile> lockfile;
    static QString curLockName;
};
