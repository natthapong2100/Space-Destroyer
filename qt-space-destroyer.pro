QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Button.cpp \
    Effect_exhaust.cpp \
    Effect_explosion.cpp \
    Effect_fire.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp \
    SpecialBullet.cpp \
    main.cpp

HEADERS += \
    Bullet.h \
    Button.h \
    Effect_exhaust.h \
    Effect_explosion.h \
    Effect_fire.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h \
    SpecialBullet.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fx_exhaust.png \
    fx_explosion.png \
    fx_fire1.png \
    fx_fire2.png \
    pro_bg1.png \
    pro_eb1.png \
    pro_eg1.png \
    pro_greenB.png \
    pro_pr1.png \
    pro_purpleB.png

RESOURCES += \
    res.qrc
