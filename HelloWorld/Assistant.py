
# import pyttsx3
# import datetime
# import wikipedia
# import speech_recognition as sr
# import webbrowser
# import os
# import random




# engine = pyttsx3.init('sapi5')
# voices = engine.getProperty('voices')
# engine.setProperty('voice', voices[1].id)



# def speak(audio):
#     engine.say(audio)
#     engine.runAndWait()

# def wishMe():
#     hour = int(datetime.datetime.now().hour)
#     if hour>=0 and hour<12:
#         print("Good Morning sir!")
#         speak("Good Morning sir!")
#     elif hour>=12 and hour<18:
#         print("Good Afternoon sir!")
#         speak("Good Afternoon sir!")
#     else:  
#         print("Good Evening sir!")
#         speak("Good Evening sir!")
#     print("I am your Assistant,how may I help you?")
#     speak("I am your Assistant,how may I help you?")

# def takeCommand():
#     r = sr.Recognizer()
#     with sr.Microphone() as source:
#         print("Listening...")
#         speak("Listening...")
#         r.pause_threshold = 1
#         audio = r.listen(source)

#     try:
#         print("Recognizing...")
#         speak("Recognizing...")
#         query = r.recognize_google(audio, language='en-in')
#         print(f"User said:{query}\n")

#     except Exception as e:
#         # print(e) 
#         print("Say that again please...")  
#         speak("Say that again please...")
#         return "None"
#     return query


# if __name__ == "__main__":
#     wishMe()  
#     while True:
#         query = takeCommand().lower() 


#         if 'wikipedia' in query:
#             speak('Searching Wikipedia...')
#             query = query.replace("wikipedia","")
#             results = wikipedia.summary(query, sentences=2)
#             speak("According to wikipedia ")
#             print(results)
#             speak(results)
#         elif 'open youtube' in query:
#             speak('okay sir')
#             webbrowser.open("youtube.com")   
#         elif 'open google' in query:
#             speak('okay sir')
#             webbrowser.open("google.com")
#         elif 'open insta' in query:
#             speak('okay sir')
#             webbrowser.open("instagram.com")
#         elif 'play music' in query:
#             Dir = 'Path for music folder.'
#             speak('okay sir')
#             songs = os.listdir(Dir)
#             print(songs)
#             os.startfile(os.path.join(Dir,songs[random.randint(numbers acc to you)])) 
#         elif 'open chrome' in query:
#             chromePath = 'Path for chrome'
#             speak('okay sir')
#             os.startfile(chromePath)
       
#         elif 'songs' in query:
#             path = 'path for songs online or offline'
#             speak('okay sir')
#             webbrowser.open(path)
#         elif 'thank you' in query:
#             print("Most Welcome sir!")
#             speak("Most Welcome sir")
#             exit()
#         elif 'play movie' in query:
#             dir = 'Pathh for movies folder '
#             speak('okay sir')
#             movie = os.listdir(dir)
#             print(movie)
#             os.startfile(os.path.join(dir,movie[random.randint(Number of videos using a,b from 0 to your last video)]))

    
            
             
