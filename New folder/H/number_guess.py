# Author : Aditya Sarwade
# Date: 20 0ctober 2023

from tkinter import *
import random

attempts =10
answer = random.randint(1,50)


def check_answer():
    global attempts
    global text

    attempts -=1
    guess =int(entry_window.get())

    if answer == guess:
        text.set("You won..!!! Congratulations")
        btn_check.pack_forget()

    elif attempts ==0:
        text.set("You are out of attempts!!!")
        btn_check.pack_forget()

    elif guess < answer:
        text.set("Incorrect:  You have "+str(attempts)+" left - GO HIGHER")

    elif guess > answer:
        text.set("Incorrect:  You have "+str(attempts)+" left - GO LOWER")

    return

root =Tk()
root.title("Guessing game")
root.geometry("500x250")
label = Label(root, text ="Heyy..Guess the number between 1 and 50")
label.pack()

entry_window = Entry(root, width = 45, borderwidth=5)
entry_window.pack()

btn_check = Button(root,text="Check",command=check_answer)
btn_check.pack()

btn_quit = Button(root, text ="Exit", command=root.destroy)
btn_quit.pack()

text = StringVar()
text.set("You have 10 attempts . Play well!!")

guess_attempts = Label(root, textvariable=text)
guess_attempts.pack()
root.mainloop()