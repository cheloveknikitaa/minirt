tell application "Finder"
	set _b to bounds of window of desktop
	set _width to item 3 of _b
	set _height to item 4 of _b
	set	myList to {_width, _height}
	set	oldDelimiters to AppleScript's text item delimiters
	set	AppleScript's text item delimiters to " "
	set	myList to myList as string
	set	AppleScript's text item delimiters to oldDelimiters
	get	myList
end tell
