import wikipedia
import wolframalpha
import wx

class MyFrame(wx.Frame):
    def __init__(self, parent, id):
        wx.Frame.__init__(self, parent, -id, 'Alex', size=(450, 100))
        
        #pos=wx.DefaultPosition, size=wx.Size(450, 100),
        #style=wx.MINIMIZE_BOX | wx.SYSTEM_MENU | wx.CAPTION |
        #wx.CLOSE_BOX | wx.CLIP_CHILDREN,
        #title="Alex"

        panel = wx.Panel(self)
        
        #my_sizer = wx.BoxSizer(wx.VERTICAL)
        
        #lbl = wx.StaticText(panel,
         #   lable = "Hello!!")       
        
        #my_sizer.Add(lbl, 0, wx.ALL, 5)
        
        self.txt = wx.TextCtrl(panel, style = wx.TE_PROCESS_ENTER, size=(400, 30))
        
        self.txt.SetFocus()
        
        self.txt.bind(wx.EVT_TEXT_ENTER, self.OnEnter)
        
        #my_sizer.Add(self.txt, 0, wx.ALL, 5)
        
        #panel.SetSizer(my_sizer)
        
        self.Show()
    
    def OnEnter(self, event):
        
        input1 = input(self.txt.GetValue())
        
        input1.lower()
        
        try:
            app_id = "U55VG4-42GXRHP9V4"
            client = wolframalpha.Client(app_id)
            res = client.query(input1)
            answer = next(res.results).text
            print (answer)
        
        except:
            print(wikipedia.summary(input1))

if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame= MyFrame(parent=None, id=-1)
    frame.Show()
    app.MainLoop()

'''
while True:
    input1 = input("Q: ")
    try:
        app_id = "U55VG4-42GXRHP9V4"
        client = wolframalpha.Client(app_id)
        res = client.query(input1)
        answer = next(res.results).text
        print (answer)
    except:
        print(wikipedia.summary(input1))
'''