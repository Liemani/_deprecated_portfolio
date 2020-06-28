//********************************************
// title = "MainViewController"
// made by Lieman at 2020.06.26
//
// description:
//	MainViewController class
//********************************************





import tkinter
import Socket


class MainViewController(tkinter.Frame):
    def __init__(self):
        super().__init__(tkinter.Tk())

        self.set_subviews()

        self.pack(fill='both')
        self.mainloop()

    def set_subviews(self):
        self.ipFrame = tkinter.Frame(self)

        self.ipLabel = tkinter.Label(self.ipFrame, width='5', text='ip: ')
        self.ipVariable = tkinter.StringVar()
        self.ipEntry = tkinter.Entry(self.ipFrame, textvariable=self.ipVariable)

        self.ipLabel.pack(side='left')
        self.ipEntry.pack(fill='x')
        self.ipFrame.pack(fill='x')


        self.portFrame = tkinter.Frame(self)

        self.portLabel = tkinter.Label(self.portFrame, width='5', text='port: ')
        self.portVariable = tkinter.StringVar()
        self.portEntry = tkinter.Entry(self.portFrame, textvariable=self.portVariable)

        self.portLabel.pack(side='left')
        self.portEntry.pack(fill='x')
        self.portFrame.pack(fill='x')


        self.socketButtonFrame = tkinter.Frame(self)

        self.connectButton = tkinter.Button(self.socketButtonFrame,
                                            text='Connect',
                                            command=self.connect_button_event)
        self.disconnectButton = tkinter.Button(self.socketButtonFrame,
                                               text='Disconnect',
                                               command=self.disconnect_button_event)

        self.connectButton.pack(side='left', fill='x')
        self.disconnectButton.pack(fill='x')
        self.socketButtonFrame.pack(fill='x')



        self.dataFrame = tkinter.Frame(self)

        self.dataLabel = tkinter.Label(self.dataFrame, width='5', text='data: ')
        self.dataVariable = tkinter.StringVar()
        self.dataEntry = tkinter.Entry(self.dataFrame, textvariable=self.dataVariable)

        self.dataLabel.pack(side='left')
        self.dataEntry.pack(fill='x')
        self.dataFrame.pack(fill='x')

        self.sendDataButton = tkinter.Button(self,
                                             text='Send Data',
                                             command=self.send_data_button_event)
        self.sendDataButton.pack(fill='x')

    def connect_button_event(self):
        self.socket = Socket.Socket((self.ipVariable.get(), int(self.portVariable.get())))

    def disconnect_button_event(self):
        self.socket.close()

    def send_data_button_event(self):
        self.socket.write(self.dataVariable.get())


viewController = MainViewController()
