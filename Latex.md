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
