package com.example.noted_project

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.core.view.ViewCompat
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class ListFragment : Fragment() {

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(
            R.layout.list,
            container,
            false,
        )
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        GlobalScope.launch(Dispatchers.Default) {
            val response = NetworkRequest.getList()

            withContext(Dispatchers.Main) {
                val series = response.results
                view.findViewById<RecyclerView>(R.id.list).apply {
                    adapter = ListAdapter(series, object : OnClickListener {
                        override fun onSerieClicked(serie: Serie, image: View) {
                            ViewCompat.setTransitionName(image, "imageTransition")
                            // val extras = FragmentNavigatorExtras(image to "imageTransition")
                            // val action = ListFragmentDirections.actionListFragment2ToDetailFragment2(
                            // product = product
                            // )
                            // findNavController().navigate(action, extras)
                        }
                    })
                }
            }
        }

        view.findViewById<RecyclerView>(R.id.list).apply {
            layoutManager = LinearLayoutManager(requireContext())
            adapter = ListAdapter(emptyList(), null)
        }
    }
}