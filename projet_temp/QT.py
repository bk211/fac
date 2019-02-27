import sys
from PyQt5.QtGui import QFont    
from PyQt5.QtWidgets import QWidget, QMessageBox, QApplication,QDesktopWidget,QMainWindow,QAction, qApp
from PyQt5.QtWidgets import (QWidget, QLabel, QLineEdit, 
    QTextEdit, QGridLayout, QApplication)



class Example(QMainWindow):
    
    def __init__(self):
        super().__init__()
        
        self.initUI()
        
        
    def initUI(self):               
        receive = QLabel('recu')
        send = QLabel('A envoyer')

        receive = QTextEdit()
        send = QLineEdit()
        self.setGeometry(300, 300, 800, 600)
        self.setWindowTitle('Simple menu')    
        self.show()

        
if __name__ == '__main__':
    
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())