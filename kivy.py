from kivy.app import App
from kivy.uix.button import Button
class MyApp(App):
    def build(self):
        self.count = 0
        return Button(
            text = "Моя первая кнопкаааа",
            font_size = 30,
            on_press = self.btn_press,
            background_color = [0.32, 0.85, 0.94, 1],
            background_normal = '')
    
    def btn_press(self, instance):
        print('кнопка нажата!')
        self.count += 1
        instance.text = 'Я нажата! ' + str(self.count) + ' раз'
        

if __name__ == '__main__':
    MyApp().run()
