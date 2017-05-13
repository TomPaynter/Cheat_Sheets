New Page:

```latex
\newpage
```

Bullet List:

```latex
		\begin{itemize}
		
		\item \textbf{Topic 1:} Topic 1.
		
		\item \textbf{Topic 2:} Topic 2
		
		\end{itemize}
```

Wrap Figure Right:

```latex
		\begin{wrapfigure}{R}{0.4\textwidth}
		\includegraphics[width=0.4\textwidth]{./Under.png}
		\caption{The final prototype's downward facing camera}
		\label{fig:Under}
		\end{wrapfigure}

```

Full Size Picture:

```latex
		\begin{figure}[h]
		\centering
		\includegraphics[width=\textwidth]{./Final.png}
		\caption{The Final Prototype}
		\label{fig:Final}
		\end{figure}
```

Footnote:

```latex 
		\footnote{footnotes working fine}
		
```

Equations:
```latex
		\begin{equation}
		 L_{\mu H} = s \times 0.008 \left[ ln \left( \frac{s \times 1.414}{2 d} \right) + 0.379 \right]
		 \label{eq:inductance}
		 \end{equation}
		
		Where:
		
		  \begin{description}
		  \setlength{\leftskip}{3cm}
		  \item[] $L_{\mu H}$ is the inductance of the coil
		  \item[] $s$ is the side length, in cm
		  \item[] $d$ is the diameter of the antenna conductor, in cm
		  
		  \setlength{\leftskip}{0cm}
		  \end{description}
		  
	  	Refferring to it again!
		 L_{\mu H} = 123
		 \tag{\ref{eq:inductance}}
		 \end{equation}
	  	
		  
		  
  ```
  
  Tables!
  
```latex
  
		\begin{table}[]
		\centering
		\caption{Loop Measurements}
		\label{measurements}
		\begin{tabular}{|c|c|c|}
		\hline
		Condition               & Inductance & Q Factor \\ \hline
		Short Leads ($\sim$5 cm) & 1.9        & 0.0064   \\ \hline
		Long Leads($\sim$50 cm)  & 2.8        & 0.52     \\ \hline
		\end{tabular}
		\end{table}
```

# LST Listing

```
\usepackage{listings}
\lstset {breaklines=true}

\usepackage{color} %red, green, blue, yellow, cyan, magenta, black, white
\definecolor{mygreen}{RGB}{28,172,0} % color values Red, Green, Blue
\definecolor{mylilas}{RGB}{170,55,241}
```
And then to import a file:
```
\lstinputlisting[language=Matlab, frame=single]{../checkFilter.m}
```
Or just write some:
```
\begin{lstlisting}[frame=single]
>>> Ex2.m
biggus dickus
>>>
\end{lstlisting}
```

For Matlab Colours:
```
\lstset{language=Matlab,%
    %basicstyle=\color{red},
    breaklines=true,%
    morekeywords={matlab2tikz},
    keywordstyle=\color{blue},%
    morekeywords=[2]{1}, keywordstyle=[2]{\color{black}},
    identifierstyle=\color{black},%
    stringstyle=\color{mylilas},
    commentstyle=\color{mygreen},%
    showstringspaces=false,%without this there will be a symbol in the places where there is a space
    numbers=left,%
    numberstyle={\tiny \color{black}},% size of the numbers
    numbersep=9pt, % this defines how far the numbers are from the text
    emph=[1]{for,end,break},emphstyle=[1]\color{red}, %some words to emphasise
    %emph=[2]{word1,word2}, emphstyle=[2]{style},
}
```

