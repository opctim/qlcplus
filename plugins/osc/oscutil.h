#ifndef OSCUTIL_H
#define OSCUTIL_H

#include <QString>
#include <QByteArray>

namespace OSCUtil
{
    static inline quint16 crcIso3309(const QString &path)
    {
        const QByteArray ba = path.toUtf8();
        quint16 crc = 0xFFFF;
        for (unsigned char b : ba)
        {
            crc ^= quint16(b) << 8;
            for (int i = 0; i < 8; ++i)
                crc = (crc & 0x8000) ? quint16((crc << 1) ^ 0x1021)
                                     : quint16(crc << 1);
        }
        return crc ^ 0xFFFF;
    }
}

#endif // OSCUTIL_H