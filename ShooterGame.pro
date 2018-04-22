TEMPLATE = app
TARGET = ShooterGame

QT = core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Player.cpp \
	Health.cpp \
	Score.cpp \
    menu.cpp \
    settings.cpp

HEADERS += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Player.h \
	Health.h \
	Score.h \
    menu.h \
    settings.h

RESOURCES += \
    res.qrc

FORMS += \
    menu.ui \
    settings.ui
