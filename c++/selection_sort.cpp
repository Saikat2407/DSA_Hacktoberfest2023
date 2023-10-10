#include <QApplication>
#include <QScreen>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Get the primary screen
    QScreen *screen = QApplication::primaryScreen();

    // Capture the whole screen
    QPixmap screenshot = screen->grabWindow(0);

    // Save the screenshot to a file
    screenshot.save("screenshot.png");

    return 0;
}
